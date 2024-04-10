import Data.List
import Data.Functor
main = do
    l <- map (read :: String -> Int) . words <$> getLine
    print $ 4 - (length $ nub l)