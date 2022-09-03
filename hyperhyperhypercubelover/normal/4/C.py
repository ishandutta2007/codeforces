n = int(input())
d = dict()
for _ in range(n):
  a = input()
  if a in d:
    print(a + str(d[a]))
    d[a] += 1
  else:
    print('OK')
    d[a] = 1