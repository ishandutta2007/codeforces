luckyFilter = filter (\c -> c == '4' || c == '7')

isLucky x = luckyFilter s == s
    where s = show x

isNearLucky x = isLucky n
    where n = length . luckyFilter $ show x

main = do
    n <- getLine
    putStrLn $ if isNearLucky n then "YES" else "NO"