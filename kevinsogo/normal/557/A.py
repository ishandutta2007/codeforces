n = input()
a1, a2 = map(int, raw_input().strip().split())
b1, b2 = map(int, raw_input().strip().split())
c1, c2 = map(int, raw_input().strip().split())

A = min(a2, n - b1 - c1)
B = min(b2, n - A - c1)
C = n - A - B
print A, B, C