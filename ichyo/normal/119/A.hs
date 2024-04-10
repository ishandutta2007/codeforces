import Control.Applicative
solve x n b
    | n < 0 = if b then 0 else 1
    | otherwise = solve (reverse x) (n - gcd (head x) n) (not b)

main = do
    [a, b, n] <- map read <$> words <$> getLine
    print $ solve [a, b] n True