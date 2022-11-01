import Data.List (intercalate)
import Data.Functor ((<$>))

solve' :: Int -> Int -> Maybe [Int]
solve' a b  | a == b = Just [a]
            | a >  b = Nothing
            | even b = (b:) <$> solve' a (b `div` 2)
            | b `mod` 10 == 1 = (b:) <$> solve' a (b `div` 10)
            | otherwise = Nothing

solve :: Int -> Int -> Maybe [Int]
solve a b = reverse <$> solve' a b

main :: IO()
main = do
    line <- getLine
    let x = map read . words $ line :: [Int]
    case solve (x !! 0) (x !! 1) of
        Just y  -> do
            putStrLn "YES"
            putStrLn $ show . length $ y
            putStrLn $ intercalate " " (map show y)
        Nothing -> putStrLn "NO"