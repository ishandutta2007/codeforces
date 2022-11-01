import Control.Monad
solve :: [[Int]] -> Int
solve [] = 0
solve (x : xs) = (if sum x > 1 then 1 else 0) + solve xs
main = do
    n <- readLn
    l <- replicateM n getLine
    print . solve $ map (map read . words) l