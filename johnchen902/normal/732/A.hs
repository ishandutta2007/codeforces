import Data.Functor

nochange :: Int -> Int -> Bool
nochange r = (`elem` [0, r]) . (`mod` 10)

solve :: Int -> Int -> Int
solve k r = head . filter (nochange r . (*k)) $ [1..]

main :: IO()
main = do
    [k, r] <- map read . words <$> getLine
    print $ solve k r