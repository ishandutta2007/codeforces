def main():
    s = "ABCD"
    arr = [len(input()) - 2 for i in range(4)]

    decides = []
    Min = min(arr)
    tmp = arr[:]; tmp.remove(Min)
    if Min * 2 <= min(tmp):
        decides.append(s[arr.index(Min)])
    
    Max = max(arr)
    tmp = arr[:]; tmp.remove(Max)
    if Max >= max(tmp) * 2:
        decides.append(s[arr.index(Max)])
    
    if len(decides) == 1:
        print(decides[0])
    else:
        print("C")

main()