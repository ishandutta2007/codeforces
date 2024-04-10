solve :: Int -> Int -> Int -> Int
solve a b c = c `div` lcm a b

main :: IO()
main = do
    [a, b, c] <- fmap (map read . words) getLine
    print $ solve a b c