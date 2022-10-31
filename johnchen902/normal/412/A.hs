import Control.Applicative

step1 n k s
	| k == 0 = forward n k s
	| k == n - 1 = backward n k s
	| k + k < n = "LEFT\n" ++ step1 n (k - 1) s
	| otherwise = "RIGHT\n" ++ step1 n (k + 1) s

forward n k s
	| k == n - 1 = "PRINT " ++ [s !! k] ++ "\n"
	| otherwise = "PRINT " ++ [s !! k] ++ "\nRIGHT\n" ++ forward n (k + 1) s

backward n k s
	| k == 0 = "PRINT " ++ [s !! k] ++ "\n"
	| otherwise = "PRINT " ++ [s !! k] ++ "\nLEFT\n" ++ backward n (k - 1) s

main = do
	[n, k] <- map read . words <$> getLine
	s <- getLine
	putStr $ step1 n (k - 1) s