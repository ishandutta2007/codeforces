module Main where

str n = putStrLn (show n ++ " 1 " ++ show n ++ " 2")

main = print 2001 >> mapM_ str [1..1000] >> str 1 >> mapM_ str [1..1000]