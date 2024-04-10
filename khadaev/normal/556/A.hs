module Main where

count _ [] = 0
count c (a:as) = 
    (if a == c then 1 else 0) + count c as

main = do
    _ <- getLine
    s <- getLine
    print $ abs (count '0' s - count '1' s)