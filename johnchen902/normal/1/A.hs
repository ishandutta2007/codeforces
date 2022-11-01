-- import Data.Int
type LL = Integer

solve :: LL -> LL -> LL -> LL
solve n m a = ((n + a - 1) `div` a) * ((m + a - 1) `div` a)

main :: IO ()
main = do
        a:b:c:[] <- fmap (map read . words) getLine
        putStrLn $ show $ solve a b c