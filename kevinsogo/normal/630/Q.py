from math import cos, pi, sqrt
a, b, c = map(int, raw_input().strip().split())
print (a**3 / sqrt(2) + b**3 * sqrt(2) + c**3 * (5 + sqrt(5)) / 4) / 6