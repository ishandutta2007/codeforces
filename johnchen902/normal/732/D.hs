import Data.Functor ((<$>))
import Data.Array
import Data.Char (isSpace)
import Data.List
import Data.Ord (comparing)
import qualified Data.ByteString.Char8 as B

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f l r
    | l == r    = r
    | f m       = bsearch f l m
    | otherwise = bsearch f (m + 1) r
    where m = (l + r) `div` 2

check :: Array Int Int -> [Int] -> Int -> Bool
check d a n = and (zipWith (\x y -> exam!x >= y) subj requ)
    where m  = snd (bounds d)
          exam = accumArray (const id) 0 (0, m) (zip a [1..n]) -- deadline
          subj = sortBy (comparing (exam!)) [1..m]  -- subjects sorted by deadline
          requ = scanl1 (+) (map (d!) subj)         -- times required for each subjects w.r.t. subj

solve :: [Int] -> [Int] -> Int
solve dl a
    | check d a (length a) = bsearch (check d a) 0 (length a)
    | otherwise            = -1
    where d = listArray (1, length dl) (map (+1) dl)

main :: IO()
main = do
    _ <- B.getLine
    a <- unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine
    d <- unfoldr (B.readInt . B.dropWhile isSpace) <$> B.getLine
    print (a `seq` d `seq` solve d a)