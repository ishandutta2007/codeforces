n = int(input())
result = 0
for i in range(1, 11):
   result += max(0, min(n, 10 ** i - 1) - (10 ** (i - 1) - 1)) * i
print(result)