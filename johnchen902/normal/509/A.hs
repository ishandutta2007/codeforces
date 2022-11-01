fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1)

solve :: Integer -> Integer
solve n = fact (2 * n) `div` (fact n * fact n)

main :: IO()
main = readLn >>= print . solve . subtract 1