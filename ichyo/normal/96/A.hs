solve [] = []
solve (x : []) = [1]
solve (x : xs)
    | x == (head xs) = (head $ solve xs) + 1 : (tail $ solve xs)
    | otherwise = 1 : solve xs

main = do
    s <- getLine
    putStrLn $ if (maximum $ solve s) >= 7 then "YES" else "NO"