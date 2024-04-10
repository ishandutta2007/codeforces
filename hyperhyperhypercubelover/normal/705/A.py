n = int(input())
for i in range(n):
  if i % 2:
    print('I love', end=' ')
  else:
    print('I hate', end=' ')
  if i + 1 < n:
    print('that', end=' ')
  else:
    print('it')