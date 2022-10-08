n = int(input())

x = list(map(int, input().split(" ")))

zap = sum(x) // n

alr = 0
res = 0
for ele in x:
  alr += zap - ele
  res += abs(alr)
print(res)