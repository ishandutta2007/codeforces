module Main where

modP = 10 ^ 9 + 7

productMod [] = 1
productMod (x:xs) = x * productMod xs `mod` modP

pow x 1 = x `mod` modP
pow x n = if n `mod` 2 == 0 then (pow x $ n `div` 2) ^ 2 `mod` modP else x * (pow x $ n - 1) `mod` modP

inverse x = pow x (modP - 2)

ans n = (((n + 2) * productMod [n + 3 .. 2 * n + 2] * inverse (productMod [1..n] * (n + 1))) - 1) `mod` modP

main = do
    n <- getLine
    print $ ans $ read n