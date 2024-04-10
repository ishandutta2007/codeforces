-- A. Exact Numbers

import Data.Char(isDigit)
import Data.List(intercalate)

split :: String -> [String]
split []      = [""]
split (',':t) = "" : split t
split (';':t) = "" : split t
split (h:t)   = (h : (head . split) t) : (tail . split) t

isInteger :: String -> Bool
isInteger x = all isDigit x && (not . null) x && x == show (read x :: Integer)

myConcat :: [String] -> String
myConcat [] = "-"
myConcat x = '\"' : (intercalate "," x) ++ "\""

process :: String -> (String, String)
process x = (myConcat (filter isInteger (split x)), myConcat (filter (not . isInteger) (split x)))

main :: IO()
main =
    do  line <- getLine
        let (a, b) = process line
        putStrLn a
        putStrLn b
        return ()