-- import Data.Char
-- import Data.Int
-- import Data.List
import Control.Monad
getList :: Read a => IO [a]
getList = fmap (map read . words) getLine

solve :: [[Int]] -> Int
solve = length . filter ((>= 2) . sum)

main :: IO ()
main = do
        n <- readLn
        a <- replicateM n getList
        putStrLn . show $ solve a