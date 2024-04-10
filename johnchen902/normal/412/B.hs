import Control.Applicative
import Data.List

main = (liftA2 ((.sort.map read.words).flip (!!).liftA2 (-) head (!!1).map read.words) getLine getLine :: IO(Int)) >>= print