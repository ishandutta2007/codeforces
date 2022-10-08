def skroc(x):
  if len(x) <= 10:
    return x
  else:
    return x[0] + str(len(x)-2) + x[-1]

n = int(input())
for i in range(n):
  print(skroc(input()))