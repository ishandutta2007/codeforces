solve :: Int -> Int -> Bool
solve a b = a + b > 0 && abs (a - b) <= 1

main :: IO()
main = do
    [a, b] <- fmap (map read . words) getLine
    putStrLn $ if solve a b then "YES" else "NO"