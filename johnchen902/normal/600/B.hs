-- B. Queries about less or equal elements

import qualified Data.ByteString.Char8 as C
import Data.List(sort)
import Data.Maybe(fromJust)

compute :: [Int] -> [Int] -> [Int]
compute a b = map snd . sort $ zip (map snd bs) (compute' (sort a) (map fst bs) 0)
    where bs = sort $ zip b [0::Int ..]
          compute' :: [Int] -> [Int] -> Int -> [Int]
          compute' _ [] _ = []
          compute' [] b' x = map (const x) b'
          compute' a'@(ah:at) b'@(bh:bt) x
              | ah <= bh  = compute' at b' (x + 1)
              | otherwise = x : compute' a' bt x

main :: IO()
main =
    do  _ <- C.getLine
        a <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
        b <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
        putStrLn . unwords . map show $ compute a b