-- import Data.List (intercalate)
-- import Data.Functor ((<$>))
import Data.Char(ord)

dig :: Char -> Integer
dig c = fromIntegral (ord c - ord '0')

myread :: String -> [Integer]
myread' :: Integer -> String -> [Integer]

myread [] = []
myread (c:t)
    | c >= '0' && c <= '9' = myread' (dig c) t
    | otherwise = myread t

myread' x [] = [x]
myread' x (c:t)
    | c >= '0' && c <= '9' = myread' (x * 10 + dig c) t
    | c == '.' = case t of
        (d:e:[])  -> [x * 100 + (dig d) * 10 + dig e]
        (d:efg@(e:f:g)) ->
            if f >= '0' && f <= '9'
            then myread' (x * 10 + (dig d)) efg
            else (x * 100 + (dig d) * 10 + dig e) : myread g
        _ -> error (t ++ " is not expected")
    | otherwise = x * 100 : myread t

myshowInteger :: Integer -> String
myshowInteger a
    | a ==   0  = "0"
    | a < 1000  = show a
    | otherwise = myshowInteger (a `div` 1000) ++ showa'
    where showa' :: String
          showa' | a' <   10 = ".00" ++ show a'
                 | a' <  100 = ".0"  ++ show a'
                 | a' < 1000 = "."   ++ show a'
                 | otherwise = error "a' < 1000"
            where a' = a `mod` 1000

myshowFrac :: Integer -> String
myshowFrac a
    | a ==  0   = ""
    | a <  10   = ".0" ++ show a
    | a < 100   = "."  ++ show a
    | otherwise = error "a < 100"

myshow :: Integer -> String
myshow a = myshowInteger (a `div` 100) ++ myshowFrac (a `mod` 100)

main :: IO()
main = interact $ myshow . sum . myread