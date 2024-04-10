s='qwertyuiopasdfghjkl;zxcvbnm,./'
d=["R","L"]
n=(-1)**d.index(input())
h=''
for i in input():
    h+=s[s.index(i)-n]
print(h)