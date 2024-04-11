from sys import *
s = input();
def check(t):
  return (t == t[::-1]) and (t != s)
for i in range(1, len(s)):
  t = s[i:] + s[:i]
  if check(t):
    print("1")
    exit()
for i in range(1, len(s)//2 + (len(s)%2)):
  t = s[-i:] + s[i:-i] + s[:i]
  if check(t):
    print("2")
    exit()

print("Impossible")