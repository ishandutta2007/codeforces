import sys
A, B, C, D = [int(i) for i in sys.stdin.read().split()]
k1 = abs(A + D + B + C)
k2 = abs(A + D - B - C)
k3 = abs(A - D + B - C)
k4 = abs(A - D - B + C)
print(abs(A * D - B * C) / max(k1, k2, k3, k4, 1))