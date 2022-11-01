-- import Data.Int
type LL = Integer

solve :: LL -> Bool
solve w = w >= 4 && even w

main :: IO ()
main = do
        w <- readLn
        putStrLn $ if solve w then "YES" else "NO"