from math import ceil
k, a, b, v = [int(i) for i in input().split()]

print(max(ceil((a/v) - b), ceil(a/(k*v))))