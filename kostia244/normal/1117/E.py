from sys import *
s = input()
s2 = ["" for i in range(len(s))]
alph = "abcdefghijklmnopqrstuvwxyz"
pos = [[[0 for k in range(24)] for j in range(26)] for i in range(27)]
for i in range(0, 10001):
  pos[i%26][i%25][i%23] = i

print("? " + (alph*(len(s)//26)) + alph[:(len(s)%26)])
t1 = input()
stdout.flush() 
print("? " + (alph[0:25]*(len(s)//25)) + alph[:(len(s)%25)])
t2 = input()
stdout.flush() 
print("? " + (alph[0:23]*(len(s)//23)) + alph[:(len(s)%23)])
t3 = input()
stdout.flush() 

for i in range(len(s)):
  s2[pos[ord(t1[i])-ord("a")][ord(t2[i])-ord("a")][ord(t3[i])-ord("a")]] = s[i]
print("! " + "".join(s2))