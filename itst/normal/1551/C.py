NUM = int(input())
for T in range(0,NUM):
    word = int(input())
    wordlist = []
    for i in range(0,word): wordlist.append(input())
    mx = 0
    for i in "abcde":
        val = []
        for j in wordlist:
            cnt = 0
            for k in j:
                cnt += 1 - 2 * (i != k)
            val.append(cnt)
        val.sort(reverse = True)
        cnt = sum = 0
        for i in val:
            if sum + i <= 0 : break
            else: cnt += 1; sum += i;
        mx = max(mx , cnt)
    print(mx)