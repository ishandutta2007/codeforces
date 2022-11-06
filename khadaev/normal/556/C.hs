module Main where
import Prelude hiding (reads)
parse x = (takeWhile (/=' ') x) : if (null rest) then [] else parse (tail $ (dropWhile (/=' ')) x) where
    rest = dropWhile (/=' ') x
read' :: String -> Int
read' = read

reads :: Int -> IO [String]
reads 0 = return []
reads k = do
    x <- getLine
    xs <- reads $ k - 1
    return (x:xs)

arithm [] = 0
arithm [_] = 1
arithm (x:y:z) = if y-x==1 then 1 + arithm (y:z) else 1

main = do
    s <- getLine
    let [n,k] = map read' $ parse s
    ranges <- reads k
    let lists = map (tail . map read' . parse) ranges
    let [st] = filter ((==1) . head) lists
    let rest = filter ((/=1) . head) lists
    print $ (length st - arithm st) + sum (map (\x -> length x - 1) rest) + (n - arithm st)