-- import Data.List (intercalate)
import System.IO (hFlush, stdout)
-- import Control.Monad (replicateM)

solve :: Int -> Int -> Int -> [Int] -> [Int]
solve a b c d = aa : bb : cc : map (subtract aa) d
    where aa = (a + c - b) `div` 2
          bb = a - aa
          cc = c - aa

query :: Int -> Int -> IO (Int)
query a b = do
    putStrLn $ "? " ++ show a ++ " " ++ show b
    hFlush stdout
    readLn

main :: IO()
main = do
    n <- readLn :: IO(Int)
    a <- query 1 2
    b <- query 2 3
    c <- query 3 1
    d <- mapM (query 1) [4 .. n]
    putStrLn $ '!' : (concat . map ((' ':) . show) $ solve a b c d)