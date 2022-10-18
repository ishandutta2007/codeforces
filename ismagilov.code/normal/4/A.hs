
f n = if and [n >= 4, n `mod` 2 == 0] then "YES" else "NO"

main = interact$f.read