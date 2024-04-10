a, b, c = map(int, input().split())

v = a**3/6/2**.5
v += b**3/3/2**.5
v += c**3*(5 + 5**.5)/24

print(v)