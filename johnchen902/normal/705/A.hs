hate :: Int -> String
love :: Int -> String

hate 1 = "I hate it"
hate n = "I hate that " ++ love (n - 1)
love 1 = "I love it"
love n = "I love that " ++ hate (n - 1)

main :: IO()
main = readLn >>= putStrLn . hate