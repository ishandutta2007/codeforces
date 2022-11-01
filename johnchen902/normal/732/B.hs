import Data.Functor

solve :: Int -> Int -> [Int] -> [Int]
solve _ _ []    = []
solve k l [a]   = [max a (k - l)]
solve k l (h:t) = let h' = max h (k - l) in h' : solve k h' t

main :: IO()
main = do
    [_, r] <- map read . words <$> getLine
    a      <- map read . words <$> getLine
    let b = solve r r a
    print $ sum b - sum a
    putStrLn . unwords . map show $ b