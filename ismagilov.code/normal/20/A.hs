


gems s x i  | i == length (s) = []
			| (s !! i) /= '/' =
				(s !! i) : gems s 0 (i + 1)
			| otherwise = 
				if x == 0 then (s !! i) : gems s 1 (i + 1)
					else gems s x (i + 1)

removeduplicates s = gems s 0 0

cutstart [] = []
cutstart s@(x:xs) 
				  | length xs == 0 = s
				  | x == '/' = cutstart xs
	              | otherwise = s

process s = reverse (cutstart (reverse (removeduplicates (s))))

main :: IO()


main = do
	--[a, b, n] <- fmap (map read . words) getLine
	s <- getLine
	putStrLn (process(s))

-- f n = if and [n >= 4, n `mod` 2 == 0] then "YES" else "NO"

-- main = interact$f.read