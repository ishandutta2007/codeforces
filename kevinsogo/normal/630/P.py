from math import pi, sin, cos
n, r = map(int, raw_input().split())
piece = (cos(2*pi / n) + cos(pi / n)) / (sin(2*pi / n) + sin(pi / n)) * sin(pi / n)**2 + (pi / n - sin(2*pi / n) / 2)
print (pi - n*piece)*r**2