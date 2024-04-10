NUM = int(input())
for T in range(0,NUM):
    cnt1 = cnt2 = 0
    dict = {}
    str = input()
    for i in range(0 , len(str)):
        sub = str[i]
        dict[sub] = dict.get(sub , 0) + 1
    for x , y in dict.items():
        cnt1 += y == 1
        cnt2 += y >= 2
    print(cnt2 + cnt1 // 2)