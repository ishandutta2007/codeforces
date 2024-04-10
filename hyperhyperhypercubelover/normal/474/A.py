a = 'qwertyuiopasdfghjkl;zxcvbnm,./'
t = input()
d = dict()
for i in range(1, len(a)):
  if t == 'L':
    d[a[i - 1]] = a[i]
  else:
    d[a[i]] = a[i - 1]
print(''.join(d[x] for x in input()))