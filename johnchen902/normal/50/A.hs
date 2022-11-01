-- import Data.Char
-- import Data.Int
-- import Data.List
-- import Control.Monad
getList :: Read a => IO [a]
getList = fmap (map read . words) getLine

solve :: Int -> Int -> Int
solve m n = m * n `div` 2

main :: IO ()
main = do
        [m,n] <- getList
        putStrLn . show $ solve m n