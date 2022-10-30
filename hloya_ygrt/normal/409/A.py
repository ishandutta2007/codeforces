


def get_arr(Len):
    buff = input().split()
    a = []
    for i in range(Len):
        a.append(int(buff[i]))
    return a

s = input()
t = input()

n = len(s)

i = 0
pt1 = 0
pt2 = 0

while i < n:
    if (s[i] == '8' and t[i] == '['):
        pt1+=1
    if (s[i] == '[' and t[i] == '('):
        pt1+=1
    if (s[i] == '('  and t[i] == '8'):
        pt1+=1

    if (t[i] == '8' and s[i] == '['):
        pt2 += 1
    if (t[i] == '[' and s[i] == '('):
        pt2 += 1
    if (t[i] == '(' and s[i] == '8'):
        pt2 += 1

    i += 2
if (pt1 == pt2):
    print("TIE")
if (pt1 > pt2):
    print("TEAM 1 WINS")
if (pt2 > pt1):
    print("TEAM 2 WINS")