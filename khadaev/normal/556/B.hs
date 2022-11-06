module Main where

parse x = (takeWhile (/=' ') x) : if (null rest) then [] else parse (tail $ (dropWhile (/=' ')) x) where
    rest = dropWhile (/=' ') x

read'::String->Int
read'=read
isOk :: Int -> [Int] -> Bool
isOk n [] = True
isOk n [x] = True
isOk n (x:y:z) = mod (x + y) n == 0 && isOk n (y:z)

word True = "Yes"
word False = "No"

main = do
    s1 <- getLine
    s2 <- getLine
    putStr $ word $ isOk (read s1) $ map (`mod` (read s1)) $ zipWith (-) [0..(read s1)-1] (map read' $ parse s2)