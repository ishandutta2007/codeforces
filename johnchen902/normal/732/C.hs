import Data.Functor
import Data.Int

solve :: Int64 -> Int64 -> Int64 -> Int64
solve 0 0 0 = 0
solve x 0 0 = 2 * (x - 1)
solve 0 x 0 = 2 * (x - 1)
solve 0 0 x = 2 * (x - 1)
solve x y 0
    | x == y = x - 1
    | x >  y = 2 * (x - 1) - y
    | x <  y = 2 * (y - 1) - x
solve x 0 y
    | x == y = x - 1
    | x >  y = 2 * (x - 1) - y
    | x <  y = 2 * (y - 1) - x
solve 0 x y
    | x == y = x - 1
    | x >  y = 2 * (x - 1) - y
    | x <  y = 2 * (y - 1) - x
solve x y z = solve (x - w) (y - w) (z - w)
    where w = min x (min y z)

main :: IO()
main = do
    [b, d, s] <- map read . words <$> getLine
    print $ solve b d s