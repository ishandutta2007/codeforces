-- C. Make Palindrome

count :: Char -> String -> Int
count = (length .) . filter . (==)

countaz :: String -> [Int]
countaz = flip map ['a'..'z'] . flip count

change :: [Int] -> [Int]
-- change x = change' (length . filter odd $ x) x
change = change' =<< length . filter odd
    where change' :: Int -> [Int] -> [Int]
          change' _ []                = []
          change' k (h:t) | even h    = h : change' k t
                          | otherwise = case k of 0 -> h - 1 : change' 0       t
                                                  1 -> h     : change' 0       t
                                                  _ -> h + 1 : change' (k - 2) t


palindrom :: [Int] -> String
palindrom x = halfString x ++ oddString x ++ (reverse . halfString) x
    where string, halfString, oddString :: [Int] -> String
          string = concat . zipWith (flip replicate) ['a'..'z']
          halfString = string . map (`div` 2)
          oddString = string . map (`mod` 2)

solve :: String -> String
solve = palindrom . change . countaz

main :: IO()
main = getLine >>= putStrLn . solve