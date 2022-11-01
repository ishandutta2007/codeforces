-- import Data.Int
-- import Control.Monad

solve :: Int -> [Int] -> Int
solve k a = length . filter (>= limit) $ a
    where limit :: Int
          limit = max (a !! (k - 1)) 1

main :: IO ()
main = do
        [_, k] <- fmap (map read . words) getLine :: IO [Int]
        a      <- fmap (map read . words) getLine :: IO [Int]
        putStrLn . show $ solve k a