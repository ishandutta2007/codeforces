import Control.Monad(replicateM)
import Data.Functor ((<$>))

solve :: [String] -> Maybe [String]
solve [] = Nothing
solve (s:t)
    | take 2 s == "OO" = Just (("++" ++ drop 2 s) : t)
    | drop 3 s == "OO" = Just ((take 3 s ++ "++") : t)
    | otherwise = (s :) <$> solve t

main :: IO()
main = do
    n <- readLn :: IO Int
    s <- replicateM n getLine
    case solve s of
        Just s' -> do
            putStrLn "YES"
            putStr (unlines s')
        Nothing ->
            putStrLn "NO"