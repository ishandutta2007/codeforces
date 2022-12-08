b = dict({"purple" : "Power", "green" : "Time", "blue" : "Space", "orange" : "Soul", "red" : "Reality", "yellow" : "Mind"})
a = dict({"Power" : 0, "Time" : 0, "Space" : 0, "Soul" : 0, "Reality" : 0, "Mind" : 0})
s = ["Power", "Time", "Space", "Soul", "Reality", "Mind"]
n = int(input())
for i in range(n):
    t = input()
    a[b[t]] = 1
print(6 - n)
for i in range(6):
    if(a[s[i]] == 0): print(s[i])