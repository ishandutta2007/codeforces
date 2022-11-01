import Control.Monad
import Data.Array
import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
getList :: Read a => IO [a]
getList = fmap (map (read . B.unpack) . B.words) B.getLine
getIntList :: IO [Int]
getIntList = fmap (unfoldr (B.readInt . B.dropWhile isSpace)) B.getLine

busstop :: [Int] -> Int
busstop (a:b:[]) = b - a
busstop _        = error "WTF"

solve :: [[Int]] -> Int
solve = maximum . scanl1 (+) . map busstop

main :: IO ()
main = do
        n <- readLn :: IO Int
        a <- replicateM n getIntList
        putStrLn . show $ solve a