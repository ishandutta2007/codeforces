n = int(input())
result = 0
for i in range(n):
  x1, y1, x2, y2 = [int(i) for i in input().split()]
  result += (x2 - x1 + 1) * (y2 - y1 + 1)
print(result)