import Data.List
import Control.Applicative

main = do
    n <- readLn :: IO Int
    l <- map (read :: String -> Int) . words <$> getLine
    let sl = scanl (+) 0 $ reverse $ sort l
        s = sum l
        in print . length $ takeWhile (\x -> 2 * x <= s) sl