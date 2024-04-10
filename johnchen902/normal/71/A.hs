-- import Data.Int
import Control.Monad
-- type LL = Integer

solve :: String -> String
solve s
    | length s <= 10 = s
    | otherwise      = [head s] ++ show (length s - 2) ++ [last s]

main :: IO ()
main = do
        n <- readLn
        replicateM_ n $ do
            s <- getLine
            putStrLn $ solve s