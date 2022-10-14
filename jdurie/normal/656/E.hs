split :: Char -> String -> [String]
split _ "" = []
split delimiter str = 
    let (start, rest) = break (== delimiter) str
        (_, remain) = span (== delimiter) rest
     in start : split delimiter remain


main :: IO()
main = getLine >>= \str -> let n = read str :: Int in sequence [getLine | x <- [1..n]] >>= \str1 -> let graph = [map read (split ' ' str2) :: [Int] | str2 <- str1] in let graph1 = [[minimum [graph!!x!!k + graph!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph2 = [[minimum [graph!!x!!k + graph!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph3 = [[minimum [graph2!!x!!k + graph2!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph4 = [[minimum [graph3!!x!!k + graph3!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph5 = [[minimum [graph4!!x!!k + graph4!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph6 = [[minimum [graph5!!x!!k + graph5!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph7 = [[minimum [graph6!!x!!k + graph6!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph8 = [[minimum [graph7!!x!!k + graph7!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph9 = [[minimum [graph8!!x!!k + graph8!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph10 = [[minimum [graph9!!x!!k + graph9!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in
    let graph11 = [[minimum [graph10!!x!!k + graph10!!y!!k | k <- [0..(n-1)]] |  y <- [0..(n-1)]] | x <- [0..(n-1)]] in putStrLn( show (maximum (map maximum graph11)))