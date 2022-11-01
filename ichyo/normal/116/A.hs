import Control.Monad
solve :: [[Int]] -> [Int]
solve [] = [0]
solve (x : xs) = (head x) - (last x) + (head $ solve xs)  : solve xs
main = do
    n <- readLn
    l <- replicateM n getLine
    print . maximum $ solve (map (map read . words) $ l)