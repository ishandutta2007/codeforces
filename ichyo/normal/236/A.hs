import Data.List
import Data.Functor
main = do
    s <- getLine
    putStrLn $ if odd (length $ nub s) then "IGNORE HIM!" else "CHAT WITH HER!"